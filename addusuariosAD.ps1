# Import active directory module for running AD cmdlets
Import-Module activedirectory
  
#Store the data from ADUsers.csv in the $ADUsers variable
$ADUsers = Import-Csv .\usuarios.csv

#Loop through each row containing user details in the CSV file 
foreach ($User in $ADUsers)
{
	#Read user data from each field in each row and assign the data to a variable as below

	$SamAccountName = $User.SamAccountName
	$Name 	= $User.Name
    $DisplayName = $User.DisplayName
    $UserPrincipalName = $User.UserPrincipalName
    $EmailAddress = $User.EmailAddress	
    $FirstName = $User.FirstName
    $LastName = $User.LastName
    $Department = $User.Department



	#Check to see if the user already exists in AD
	if (Get-ADUser -F {SamAccountName -eq $Name})
	{
		 #If user does exist, give a warning
		 Write-Warning "A user account with username $Name already exist in Active Directory."
	}
	else
	{
		#User does not exist then proceed to create the new user account
		
        #Account will be created in the OU provided by the $OU variable read from the CSV file
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
            -AccountPassword (ConvertTo-SecureString "Posredes123*" -AsPlainText -Force) 
	}
}