FROM	alpine:latest

RUN apk add --update --no-cache nginx openssh openssl supervisor wget

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

COPY index.html /etc/nginx/
COPY nginx.conf /etc/nginx/
COPY ssl_params.conf /etc/nginx/
COPY telegraf.conf /etc/telegraf/
COPY supervisord.conf /etc/supervisord.conf
COPY start.sh ./

EXPOSE 80 443 22

ENTRYPOINT ["/bin/sh", "start.sh"]
