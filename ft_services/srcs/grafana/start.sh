#!/bin/sh

rm -rf /var/cache/apk/*

# Starting of services
#/usr/bin/supervisord -c /etc/supervisord.conf
#rm /etc/telegraf.conf && telegraf &
#telegraf & 
#/usr/sbin/grafana-server --homepath=/usr/share/grafana
#/usr/sbin/grafana-server --homepath=/usr/share/grafana

/usr/bin/supervisord -c /etc/supervisord.conf
