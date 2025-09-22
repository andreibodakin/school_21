FROM alpine:latest

RUN		apk update && apk upgrade
RUN		apk add mariadb mariadb-client openrc supervisor

RUN		mkdir "/run/mysqld" && chown -R mysql /run/mysqld

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

VOLUME	["/sys/fs/cgroup"]

COPY	create_db.sql .
COPY	my.cnf /etc/
COPY	wp_db.sql .
COPY	start.sh .

COPY telegraf.conf /etc/telegraf/
COPY supervisord.conf /etc/supervisord.conf

RUN		chmod +x start.sh

VOLUME	["/var/lib/mysql"]

EXPOSE	3306

CMD		sh start.sh