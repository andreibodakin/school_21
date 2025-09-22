FROM	alpine:latest

RUN		apk update && apk upgrade
RUN		apk add wget nginx openrc supervisor php7 php7-fpm php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session

RUN		apk add openrc nginx supervisor

RUN		adduser -D -g 'www' www

RUN		mkdir /www && chown -R www:www /var/lib/nginx && chown -R www:www /www 

RUN		wget https://wordpress.org/latest.zip
RUN		unzip latest.zip
RUN		mv wordpress /www/
RUN		rm latest.zip

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
COPY	nginx.conf /etc/nginx/conf.d/default.conf
COPY	supervisord.conf /etc/supervisord.conf
COPY	wp-config.php /www/wordpress

COPY	start.sh .
RUN 	chmod 711 start.sh

EXPOSE	5050

CMD		sh start.sh
