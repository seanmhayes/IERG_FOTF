<?php 
$i = 0;
session_start();

//******Check if the variables have already been set for this WebServer Session. If not, set them.*****
//Increment "Line" to parse next line of CSV each time this PHP script is called
$_SESSION['line'] = isset($_SESSION['line']) ? ++$_SESSION['line'] : 0;
$_SESSION['windSp'] = isset($_SESSION['windSp']) ? $_SESSION['windSp'] : "lo";
$_SESSION['prLine'] = isset($_SESSION['prLine']) ? $_SESSION['prLine'] : "off";
$_SESSION['comp'] = isset($_SESSION['comp']) ? $_SESSION['comp'] : "on";

//Load the Data from the next line of CSV file
$handle = fopen('data\allData.csv', 'r');
while(($dataVals = fgetcsv($handle, 1000, ',')) && $i <= $_SESSION['line']) {
    $i++;
}
if(!$dataVals) {
   $_SESSION['line'] = 0;
}

//Set the Time to be GMT +1 (ie daylight savings)
header("Content-type: text/json");
date_default_timezone_set('EUROPE/HELSINKI');
$time = (time()+3600)*1000;

//Check if there's been any changes from Dashboard to WindSpeed, Prod. Line, etc. and initialise values.
//$POST is checking whether they've been updated by a HTTP POST request from the Dashboard Page Ajax code
if (isset($_POST['windSp'])) {
	$_SESSION['windSp'] = $_POST['windSp'];
}

if (isset($_POST['prLine'])) {
	$_SESSION['prLine'] = $_POST['prLine'];
}

if (isset($_POST['comp'])) {
	$_SESSION['comp'] = $_POST['comp'];
}

// Set Variables depending on the above. dataVals stores an array of columns from the current row of the CSV
if ($_SESSION['windSp'] == "lo") {
 	$windSp = (float)$dataVals[0];
 	$windProd = (float)$dataVals[2];
} elseif ($_SESSION['windSp'] == "hi") {
 	$windSp = (float)$dataVals[1];
 	$windProd = (float)$dataVals[3];
}

if ($_SESSION['prLine'] == "off") {
	$prLineLoad = 0;
} elseif ($_SESSION['prLine'] == "on") {
	$prLineLoad = (float)$dataVals[6];
}

if ($_SESSION['comp'] == "off") {
	$compLoad = 0;
} elseif ($_SESSION['comp'] == "on") {
	$compLoad = (float)$dataVals[5];
}

$baseLoad = (float)$dataVals[4];

$totalLoad = $prLineLoad + $baseLoad + $compLoad;
$esbProd = $totalLoad - $windProd;
$reactorGas = (float)$dataVals[9];
$reactorTemp = (float)$dataVals[10];
$boilerGas = (float)$dataVals[7];
$boilerTemp = (float)$dataVals[8];
// Create a PHP array and echo it as JSON
$ret = array($time, $windSp, $windProd, $baseLoad, $compLoad, $prLineLoad, $totalLoad, $esbProd, $boilerGas, $boilerTemp, $reactorGas, $reactorTemp);
echo json_encode($ret);

?>
