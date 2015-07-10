<?php

require 'Phant.php';
$_endpoint = 'http://data.sparkfun.com';
$_pubhash = "roblD1WnY6HzxgDOv67L";
$_privhash = "jkzWoer0gEtBMebE9xjd";
$phant = new Phant($_endpoint, $_pubhash, $_privhash);

// $data = array(
//     'highwind' => '21.7',
//     'lowwind' => '43.2',
// );



$handle = fopen("WindSpeed.csv", "r");
$default = ini_get('max_execution_time');
set_time_limit(3600);


while (($windVals = fgetcsv($handle, 10000, ",")) !== FALSE) {
	$data = array(
		'highwind' => $windVals[0],
		'lowwind' => $windVals[1],
		);
	print_r($phant->input($data));
	sleep(10);
}

set_time_limit($default);
fclose($handle);

// print_r($phant->input($data));

?>