# importa o modulo do active diretory
Import-Module activedirectory
  
#Atribui a lista de usuarios na variavel $ADUusers com o formato csv
$ADUsers = Import-Csv .\usuarios.csv

#faz a interação da lista
foreach ($User in $ADUsers)
{
	#faz a isteração de cada campo de cada linha nas respetivas variaveis

	$SamAccountName = $User.SamAccountName
	$Name 	= $User.Name
    $DisplayName = $User.DisplayName
    $UserPrincipalName = $User.UserPrincipalName
    $EmailAddress = $User.EmailAddress	
    $FirstName = $User.FirstName
    $LastName = $User.LastName
    $Department = $User.Department



	#Verifica se o usuario já existe no AD
	if (Get-ADUser -F {SamAccountName -eq $Name})
	{
		 #Se o usuario existir mostra uma mensagem para usu
		 Write-Warning "Um usuario com a conta $Name já existe no AD";
	}
	else
	{
		#Se o usuario não existir cria uma nova alocação de memoria para o respectivo usuario
		
        #instacia com os respetivos atributos inerentes ao usuario
		New-ADUser `
            -SamAccountName "$SamAccountName" `
            -UserPrincipalName "$UserPrincipalName" `
            -Name "$Name" `
            -DisplayName "$DisplayName" `
            -Path "CN=Users,DC=posredes,DC=com" `
            -GivenName  "$FirstName" `
            -SurName "$LastName" `
            -EmailAddress "$EmailAddress" `
            -Department "$Department" `
            -Enabled $True `
            #Converter o texto da senha simples em um padrão de hashing
            -AccountPassword (ConvertTo-SecureString "suasenhaaqui*" -AsPlainText -Force) 
	}
}