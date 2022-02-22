#!/bin/bash

echo "----------------------"
echo "| Iniciando Montagem |"
echo "----------------------"

sleep 1
test -d ~/pendrive

if [ $? -eq 0 ]; then

  echo "+ Diretorio já existe !!!"

else 
  
  echo "+ Diretorio sendo criado"
  echo " "
sleep 1
  mkdir -p ~/pendrive

fi

  df -h | grep sd[b-x] > /dev/null 2>&1
 
 echo "+ Detectando unidade"
 echo " "
sleep 1
if [ $? -eq 0 ]; then
  df -h | grep sd[b-x] | cut -d "s" -f2 |cut -d " " -f1

read op  

  echo "+ Unidade encontrada"
  echo " "
 
  sleep 1
  sudo mount /dev/s$op ~/pendrive
   
  echo "-------------------------------------------"
  echo "| Dispositivo montado em "$HOME"/pendrive |"
  echo "-------------------------------------------"
else
   echo " "
   echo "Unidade não encontrade!!!"
fi
