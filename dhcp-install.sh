#!/bin/bash


#Install servico DHCP by RP


stty -echo

read -p "Informe sua senha: " pass  

stty echo

echo -e  "\n[ Atualizando sistema ] \n"

echo $pass | sudo -S  apt update -y

echo -e "\n[ Instalando pacote do servico DHCP ] \n"

echo $pass | sudo -S  apt install isc-dhcp-server -y

sleep 2

echo -e  "\n[ Movendo arquivo de conf ] \n" 

mv /etc/dhcp/dhcpd.conf /etc/dhcp/dhcpd.conf.bkp -v

read -p "Informe a rede ex 192.168.0.0 : " rede

read -p "Informe o inicio do range ex: 192.168.0.11: " inicio

read -p "Informe o final do range ex: 192.168.0.254: " fim

read -p "Informe o nome de dominio: " dominio

read -p "IP do servidor de dominio: " ipdomain

read -p "Informe o gateway da rede: " gateway


echo -e "#Configuracao basica de servidor DHCP by RP MAX \n" >> /etc/dhcp/dhcpd.conf

echo -e  "\n\ndefault-lease-time 600;\nmax-lease-time 7200;\n\n" >> /etc/dhcp/dhcpd.conf

echo -e  "subnet $rede netmask 255.255.255.0 { \n\n range $inicio $fim;\n option routers $gateway;" >> /etc/dhcp/dhcpd.conf

echo -e  " option domain-name-servers $ipdomain;\n option domain-name \"$dominio\";\n\n}" >> /etc/dhcp/dhcpd.conf

echo -e "\nConfigurando arquivo /etc/default/isc-dhcp-server\n" 

eth=$(ip -br link | awk '$2 ~ /UP/ {print $1}' | grep -v -e "lo" -e "w" | tail -n 1) && \

sed -i -e "s/#INTERFACESv4=\"/INTERFACESv4=\"$eth/" /etc/default/isc-dhcp-server 

echo -e "\n[ Parando o servico DHCP caso esteja rodando ]\n"

echo $pass | sudo -S systemctl stop isc-dhcp-server 

sleep 3

echo -e "\n[ Iniciando servico de DHCP Server ]\n"

echo $pass | sudo -S systemctl start isc-dhcp-server

sleep 3

echo -e "\n[ Checando status do servico DHCP Server ]\n"

sleep 3
echo $pass | sudo -S systemctl status isc-dhcp-server

unset pass

echo -e "\n[ --- PROCESSO CONCLUIDO ---- ]"















