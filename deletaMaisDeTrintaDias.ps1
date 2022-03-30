<#
    Autor: RP
    
    Descrição:  Script de deleção de arquivos com mais de 30 dias

#>




$path ="C:\Users\$env:USERNAME\Desktop\Powershell\Scripts\FOTOS"

$fotos = Get-ChildItem | Where-Object{$_.LastWriteTime -lt (Get-Date).AddDays(-30)}

foreach($foto in $fotos){

   remove-item $path\$foto
   
   write-host "Removendo item $foto" 

}