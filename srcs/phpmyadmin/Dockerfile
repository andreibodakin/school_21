FROM	alpine:latest

RUN		apk update && apk upgrade
RUN		apk add nginx openrc supervisor wget

RUN		apk add php7 php7-fpm php7-mysqli \ 
		php7-zlib php7-curl php7-mbstring \
		php7-json php7-session

RUN		mkdir -p /run/nginx && chown -R nginx:nginx /run/nginx

RUN		adduser -D -g 'www' www

RUN		mkdir /www && chown -R www:www /var/lib/nginx && chown -R www:www /www

RUN		wget http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN		tar zxvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN		mv phpMyAdmin-5.0.2-all-languages /www/phpmyadmin
RUN		rm phpMyAdmin-5.0.2-all-languages.tar.gz

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.16.1_static_linux_amd64.tar.gz
RUN tar -xvf telegraf-1.16.1_static_linux_amd64.tar.gz && rm -rf telegraf-1.16.1_static_linux_amd64.tar.gz
RUN mv telegraf-1.16.1/etc/telegraf etc/telegraf
RUN mv telegraf-1.16.1/etc/logrotate.d /etc/logrotate.d
RUN mv telegraf-1.16.1/usr/bin/telegraf usr/bin/telegraf
RUN chmod +x usr/bin/telegraf
RUN mv telegraf-1.16.1/usr/lib/telegraf usr/lib/telegraf
RUN chmod +x usr/lib/telegraf/scripts/init.sh
RUN chmod +x usr/lib/telegraf/scripts/telegraf.service
RUN mv telegraf-1.16.1/var/log/telegraf var/log/telegraf

COPY telegraf.conf /etc/telegraf/
COPY	my_config/nginx.conf /etc/nginx/conf.d/default.conf
COPY    my_config/config.inc.php /www/phpmyadmin/
COPY 	my_config/supervisord.conf /etc/supervisord.conf
COPY    start.sh .

RUN 	chmod 711 start.sh

EXPOSE	5000

CMD		sh start.sh