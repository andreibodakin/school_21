#!/bin/bash

#Changing owner and permission
chown -R www-data:www-data /var/www/*
chmod -R 755 /tmp/*

#Creating ssl key and certificate
openssl req -newkey rsa:4096 -x509 -sha256 -nodes -days 365 \
	-keyout /etc/ssl/certs/test.key \
	-out /etc/ssl/certs/test.crt \
	-subj "/C=RF/ST=Moscow/L=Moscow/O=School21/OU=ft_server/CN=klavada"

#Configuring nginx
rm -rf etc/nginx/sites-available/default
mv tmp/default etc/nginx/sites-available/default

#Configuring Wordpress
wget https://wordpress.org/latest.tar.gz
tar -xzvf latest.tar.gz
rm -rf latest.tar.gz
mv wordpress var/www/wordpress
mv tmp/wp-config.php var/www/wordpress

#Configuring PhpMyAdmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xzvf phpMyAdmin-5.0.2-all-languages.tar.gz
rm -rf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages /var/www/phpMyAdmin-5.0.2-all-languages
mv tmp/config.inc.php /var/www/config.inc.php

#Configuring MySQL
service mysql start
echo "CREATE USER 'admin'@'localhost';" | mysql -u root
echo "CREATE DATABASE klavada_db;" | mysql -u root
echo "GRANT ALL PRIVILEGES ON klavada_db.* TO 'admin'@'localhost' identified by 'pass';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

#Moving autoindex.sh to root
mv /tmp/autoindex.sh ../

#Starting mysql and  nginx
service php7.3-fpm start
service nginx start

bash
