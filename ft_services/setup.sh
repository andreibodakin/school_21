#!/bin/sh

echo "Minikube go go go!"
minikube start --vm-driver=virtualbox --disk-size="7000mb" --memory="3000mb"

echo "Minikube addons go go go!"
minikube addons enable metallb
minikube addons enable dashboard
minikube addons enable metrics-server

IP=$(minikube ip)

#Switching docker daemon to minikube
eval $(minikube docker-env)

echo "Building images..."
docker build -t nginx srcs/nginx
docker build -t ftps srcs/ftps
docker build -t phpmyadmin srcs/phpmyadmin
docker build -t wordpress srcs/wordpress
docker build -t mysql srcs/mysql
docker build -t grafana srcs/grafana
docker build -t influxdb srcs/influxdb

echo "Creating pods and services..."
kubectl apply -f srcs/configmap.yaml
kubectl apply -f srcs/nginx.yaml
kubectl apply -f srcs/ftps.yaml
kubectl apply -f srcs/phpmyadmin.yaml
kubectl apply -f srcs/wordpress.yaml
kubectl apply -f srcs/mysql.yaml
kubectl apply -f srcs/grafana.yaml
kubectl apply -f srcs/influxdb.yaml

#Setup metalLB secret
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

#Opening of dashboard
(kubectl proxy &) &>/dev/null
(minikube dashboard &) &>/dev/null
