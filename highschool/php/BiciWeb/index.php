<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Home</title>
    <link rel="stylesheet" href="https://unpkg.com/leaflet@1.7.1/dist/leaflet.css"
    integrity="sha512-xodZBNTC5n17Xt2atTPuE1HxjVMSvLVW9ocqUKLsCC5CXdbqCmblAshOMAS6/keqq/sMZMZ19scR4PsZChSR7A=="
    crossorigin=""/>
    <script src="https://unpkg.com/leaflet@1.7.1/dist/leaflet.js"
   integrity="sha512-XQoYMqMTK8LvdxXYG3nZ448hOEQiglfqkJs1NOQV44cWnUrBc8PkAOcXy20w0vlaXaVUearIOBhiXZ5V3ynxwA=="
   crossorigin=""></script>
   <link rel="stylesheet" href="style.css">
   <link rel="stylesheet" href="index.css">
</head>
<body>
    <div id="title">
        Mappa stazioni
    </div>
    <div id="button">
        <button onClick="document.location.href = 'login.php'">Admin</button>
    </div>

    <div id="mapid"></div>

<script>
var mymap = L.map('mapid').setView([45.5467, 11.5481], 14);
L.tileLayer('https://api.mapbox.com/styles/v1/{id}/tiles/{z}/{x}/{y}?access_token={accessToken}', {
    attribution: 'Map data &copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors, Imagery © <a href="https://www.mapbox.com/">Mapbox</a>',
    maxZoom: 18,
    id: 'mapbox/streets-v11',
    tileSize: 512,
    zoomOffset: -1,
    accessToken: 'pk.eyJ1Ijoic3RvcnRvIiwiYSI6ImNrbGdpYzV0ajB5bngyb3ByNXNrcWkxYTkifQ.4F-ESrCBLDMU1KFFc8Nk4w'
}).addTo(mymap);
var markMainStation = L.marker([45.54147, 11.54076]).addTo(mymap);
var markSeagullStation = L.marker([45.54694, 11.54289]).addTo(mymap);
var markGooseStation = L.marker([45.54730, 11.54690]).addTo(mymap);

markMainStation.on('click', function() { getSlotInfo(markMainStation, 1); });
markSeagullStation.on('click', function() { getSlotInfo(markSeagullStation, 2); });
markGooseStation.on('click', function() { getSlotInfo(markGooseStation, 3); });

function getSlotInfo(station, id){
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            station.bindPopup("<b>Station " + id + "</b><br>" + this.responseText).openPopup();
        }
    };
    xmlhttp.open("GET", "get_slot_info.php?id=" + id, true);
    xmlhttp.send();
}
</script>
</body>
</html>