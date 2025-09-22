#!/bin/sh

rm -rf /var/cache/apk/*

# Generation of SSL
openssl req	-newkey rsa:2048 \
		-x509 \
		-sha256 \
		-nodes \
		-days 365 \
		-keyout /etc/ssl/ssl.key \
		-out /etc/ssl/ssl.crt \
		-subj "/C=RU/ST=Moscow/L=Moscow/O=School21/OU=IT/CN=klavada"

# Creating ftps user zdawnsta as admin
echo -e "school21\nschool21" | adduser klavada --home /home/klavada

echo "Test file" > /home/klavada/test

# Starting of services
/usr/bin/supervisord -c /etc/supervisord.conf