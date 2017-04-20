$ip = "192.168.0.40";
if($ip =~ /^([0-9]|[0-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])$/){
	print"ipv4";
}
else {
	print"not\n";
}
if($ip =~ /^(\d{1,3}\.){3}\d{1,3}$/) {
	print"ipv4 address\n";
}
else {
	print"not a valid\n";
}



