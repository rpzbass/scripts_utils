<#
  .Autor :By Ronaldo
  .Description

   Verifica a disponibilidade de IP.
#>

ipconfig /all

echo " "
echo "INFORME A REDE: ex : 192.168.0"
echo " "
$rede = Read-Host;

echo "INFORME O FIM DO ESCOPO: "
echo " "
$fim = Read-Host;

for ($i = 0;$i -le $fim;$i++){

    ping -n 1 "$rede.$i"

}





