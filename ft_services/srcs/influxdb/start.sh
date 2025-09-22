#!/bin/sh

rm -rf /var/cache/apk/*

# Completing of influxdb config
echo "auth-enabled = true" >> /etc/influxdb.conf

# Starting of influxd service
/usr/sbin/influxd &
sleep 5

# Creation of telegraf db to get all metrics
echo "CREATE DATABASE telegraf" | influx
echo "CREATE USER klavada WITH PASSWORD 'school21' WITH ALL PRIVILEGES" | influx

# Starting of services
/usr/bin/supervisord -c /etc/supervisord.conf
