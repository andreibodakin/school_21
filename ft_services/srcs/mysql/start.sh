openrc default
/etc/init.d/mariadb setup
rc-service mariadb start
mysql < create_db.sql
mysql -u root wp_db < wp_db.sql
rc-service mariadb stop

/usr/bin/supervisord -c /etc/supervisord.conf
