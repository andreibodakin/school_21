FROM alpine:latest

RUN apk add --no-cache grafana --repository=http://dl-cdn.alpinelinux.org/alpine/edge/community

#RUN apk add --update --no-cache telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted
#RUN apk add --update --no-cache grafana --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted
RUN apk add --update --no-cache supervisor wget
EXPOSE 3000

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

WORKDIR /usr/share/grafana

#COPY grafana.db /usr/share/grafana/data/

COPY telegraf.conf /etc/telegraf/
COPY custom.ini /etc/grafana/conf/
COPY datasources.yml /usr/share/grafana/conf/provisioning/datasources/influxdb.yaml
COPY dashboard.yml /usr/share/grafana/conf/provisioning/dashboards/dashboards.yaml
COPY my_json/* /var/lib/grafana/dashboards/
COPY start.sh ./

COPY supervisord.conf /etc/supervisord.conf

ENTRYPOINT ["/bin/sh", "./start.sh"]
