// -----------------------------
// HALAMAN WEB UNTUK SETTING JWS

char setwaktu[] PROGMEM = R"=====(

<!DOCTYPE HTML>
<html>
<meta name='viewport' content='width=device-width, initial-scale=1'>

<head>
<title>JAM WAKTU SHOLAT DIGITAL</title>
<style> body { width: 97% ; text-align: center; } input, select, button, textarea { max-width: 100% ; margin: 5px; padding: 5px; border-radius: 7px; } meter, progress, output { max-width: 100% ; } h1 { color: grey; } .note { color: #555; font-size:1em;} .info { background-color: #eee; border-radius: 3px; padding-top: 17px; margin: 5px;} .tombol { background-color: #ccc; margin: 20px; padding: 10px; border-radius: 10px; text-decoration: none;}</style>
<style>


.ws table {
  font-family: arial, sans-serif;
  border-collapse: collapse;
  width: 100%;
}

.ws td, th {
  border: 1px solid #dddddd;
  text-align: left;
  padding: 8px;
}

.ws tr:nth-child(even) {
  background-color: #dddddd;
}

</style>
</head>

<body onload='updateData()'>
    <table width='100%'>
        <tr>
            <td>
                <img width='100' height='80' src="data:image/png;base64,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" alt="">
            </td>
            <td>
                <h2>JWS DIGITAL</h2>
                <h2>Teknik Elektro</h2>
                <h2>Universitas Pertamina</h2>
            </td>
            <td>
                <img width='100' height='80' src="data:image/png;base64,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" alt="">
            </td>
        </tr>
    </table>



<div class='info'>
  <span id='day'></span>/<span id='month'></span>/<span id='year'></span><span> </span>
  <span id='hour'></span>:<span id='minute'></span>:<span id='second'></span><span> </span>
  <span id='temp'></span><span>C</span><br><br>
</div>

<h2>Ubah Waktu</h2>

<table width='100%'>
  <tr>
      <td colspan="2">
          <h3>Selaraskan Otomatis</h3>
      </td>
  </tr>
  <tr>
      <td colspan="2">
          <button onclick="selaraskan()" style="background-color: #8affff">Selaraskan</button>
      </td>
  </tr>
  <tr>
      <td colspan="2">
          <h3>Atur Manual</h3>
      </td>
  </tr>
  <tr>
    <td>
      <form>
        <h4>Tanggal</h4>  
        <input type='date' name='date' min='2019-01-01'><br><br>
        <input type='submit' value='Ubah Tanggal'> 
      </form>  
    </td>
    <td>
      <form>  
        <h4>Jam</h4>
        <input type='TIME' name='time'><br><br>
        <input type='submit' value='Ubah Jam'> 
      </form>
    </td>
  </tr>
</table>
<table width='100%'> 

</table>
<br><br>
<hr/>
<br><br>
<h2>Jadwal Sholat Hari Ini</h2>
<div align="center">
      <table style="border: 1px solid" class="ws">
        <tr>
          <td>Imsyak</td>
          <td id="wsim">0:0:0</td>
        </tr>
        <tr>
          <td>Shubuh</td>
          <td id="wssh">0:0:0</td>
        </tr>
        <tr>
          <td>Terbit</td>
          <td id="wstr">0:0:0</td>
        </tr>
        <tr>
          <td>Dhuha</td>
          <td id="wsdh">0:0:0</td>
        </tr>
        <tr>
          <td>Dzuhur</td>
          <td id="wsdz">0:0:0</td>
        </tr>
        <tr>
          <td>Ashar</td>
          <td id="wsas">0:0:0</td>
        </tr>
        <tr>
          <td>Maghrib</td>
          <td id="wsma">0:0:0</td>
        </tr>
        <tr>
          <td>Isya</td>
          <td id="wsis">0:0:0</td>
        </tr>
      </table>
</div>


<br>
<hr/>
<br><br>
<h2>Setting JWS</h2>
<h3>Iqomah</h3>

<form>
<table width='100%'>
  <tr>
    <td>
      <label for="iqmhs">Subuh</label><br>
      <input id="iqmhs" placeholder="12" maxlength="2" size="3"/>
    </td>
    <td>
      <label for="iqmhd">Dzuhur</label><br>
      <input id="iqmhd" placeholder="8" maxlength="2" size="3"/>
    </td>
    <td>
      <label for="iqmha">Ashar</label><br>
      <input id="iqmha" placeholder="6" maxlength="2" size="3"/>
    </td>
  </tr>
  <tr>
    <td>
      <label for="iqmhm">Maghrib</label><br>
      <input id="iqmhm" placeholder="5" maxlength="2" size="3"/>
    </td>
    <td>
      <label for="iqmhi">Isya</label><br>
      <input id="iqmhi" placeholder="5" maxlength="2" size="3"/>
    </td>
    <td>
      <label for="durasiadzan">Adzan</label><br>
      <input id="durasiadzan" placeholder="2" maxlength="2" size="3"/>
    </td>
  </tr>
</table>
<table width='100%'>
  <tr>
    <td>
      <label for="latitude">Latitude</label><br>
      <input id="latitude" placeholder="-6.230900" size="9"/>
    </td>
    <td>
      <label for="longitude">Longitude</label><br>
      <input id="longitude" placeholder="106.778941" size="9"/>
    </td>    
  </tr>
  <tr>
    <td>
      <label for="zonawaktu">Zona Waktu</label><br>
      <input id="zonawaktu" placeholder="7" size="3"/>
    </td>
    <td>
      <label for="ihti">Ihtiyati</label><br>
      <input id="ihti" placeholder="2" maxlength="2" size="3"/>
    </td>
  </tr>
  <tr>
    <td>
      <label for="hilal">Hilal</label><br>
      <input id="hilal" placeholder="2" maxlength="2" size="3"/>
    </td>
    <td>
      <label for="hijriah">Koreksi Hijriah</label><br>
      <input type="number" id="koreksihjr" placeholder="0" size="3" min="-3" max="3"/>
    </td>
  </tr>
  
  <tr>
      <td colspan="2">
            <input type="checkbox" name="imsyak" id="dispimsyak">
            <label for="imsyak"> Tampilkan Imsyak</label><br>
            
            <input type="checkbox" name="Aimsyak" id="ringimsyak">
            <label for="Aimsyak"> Aktifkan Alarm Imsyak</label><br>
            
            <input type="checkbox" name="disppuasa" id="disppuasa" checked>
            <label for="disppuasa"> Tampilkan pengingat puasa</label><br>

            <input type="checkbox" name="dispdhuha" id="dispdhuha">
            <label for="dispdhuha"> Tampilkan Waktu Dhuha</label><br>

            
            <input type="checkbox" name="iden" id="dispiden" checked>
            <label for="dispiden"> Tampilkan Identitas</label><br><br>
      </td>
  </tr>
</table>
<br>
<div>
  <button onClick="setJws()"> Simpan </button>
</div>
</form>

<br><br>
<hr/>
<br><br>


<h3>Informasi</h3>
<form>
  <div>
    <label for="namamasjid">Nama Masjid</label><br>
    <textarea rows="3" id="namamasjid" placeholder="Musholla Al-Istiqomah"/></textarea>
  </div>
  <div>
    <label for="informasi">Informasi Tambahan</label><br>
    <textarea rows="3" id="informasi" placeholder="belum diisi"/></textarea>
  </div>
  <div>
    <br>
    <button onClick="setJws()"> Simpan </button>
  </div>
</form>

<br><br>
<hr/>
<br><br>



<h2>Ubah Kecerahan</h2>
<table width='100%'> 
    <tr>
        <td>
            <input type="range" min="0" max="150" value="75" id="br" onchange="setBr()" style="width: 100%;">
        </td>
    </tr>
</table>




<br>
<hr/>
<br><br>


</body>


<script>

var xmlHttp=createXmlHttpObject();
//var xmlHttp=createXmlHttpObject();

function createXmlHttpObject(){
 if(window.XMLHttpRequest){
    xmlHttp=new XMLHttpRequest();
 }else{
    xmlHttp=new ActiveXObject('Microsoft.XMLHTTP');// code for IE6, IE5
 }
 return xmlHttp;
}

function updateData() {
  prosesdatajws();
  proseswaktu();
}

function proseswaktu(){
 if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
   xmlHttp.open('POST','xmlwaktu',true);
   xmlHttp.onreadystatechange=handleServerResponseWaktu;
   xmlHttp.send(null);
 }
 setTimeout('proseswaktu()',1000);
}

function cekws(){
  document.getElementById('wsim').innerHTML="masuk";
}

function prosesdatajws(){
 if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
   xmlHttp.open('PUT','xmldatajws',true);
   xmlHttp.onreadystatechange=handleServerResponseDataJWS;
   xmlHttp.send(null);
 }
}

function setBr(){
    let br = document.getElementById('br').value
    console.log(br)
    
    let dataJson = {cerah:br}


    var xhr = new XMLHttpRequest();
    var url = "/kecerahan";

    xhr.onreadystatechange = function() {
        if(this.onreadyState == 4  && this.status == 200) {
        console.log(xhr.responseText);
        console.log("hahah");
        }
    };
    xhr.open("POST", url, true);
    xhr.send(JSON.stringify(dataJson));
    xhr.onloadend = function(){
        console.log(xhr.status);
        if(this.status == 200) {
        var myObj = JSON.parse(this.responseText);
        console.log(myObj);
        }else{
        setBr();
        }

    }

    console.log(dataJson)
}


function handleServerResponseWaktu(){
  
 if(xmlHttp.readyState==4 && xmlHttp.status==200){
//   xmlResponse=xmlHttp.responseXML;
   var data = xmlHttp.responseText;
//   console.log(data);
   var myObj = JSON.parse(data);

   //  xmldoc = xmlResponse.getElementsByTagName('Tahun');
  //  message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('year').innerHTML=myObj.rTah;

  //  xmldoc = xmlResponse.getElementsByTagName('Bulan');
  //  message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('month').innerHTML=myObj.rBul;

  //  xmldoc = xmlResponse.getElementsByTagName('Tanggal');
  //  message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('day').innerHTML=myObj.rTgl;

  //  xmldoc = xmlResponse.getElementsByTagName('Jam');
  //  message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('hour').innerHTML=myObj.rJam;

  //  xmldoc = xmlResponse.getElementsByTagName('Menit');
  //  message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('minute').innerHTML=myObj.rMen;

  //  xmldoc = xmlResponse.getElementsByTagName('Detik');
  //  message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('second').innerHTML=myObj.rDet;

  //  xmldoc = xmlResponse.getElementsByTagName('Suhu');
  //  message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('temp').innerHTML=myObj.rSuhu;
   
 }
 
}


function handleServerResponseDataJWS(){
  
 if(xmlHttp.readyState==4 && xmlHttp.status==200){
//   xmlResponse=xmlHttp.responseXML;
   let data = xmlHttp.responseText;
   console.log(data);
   var myObj = JSON.parse(data);

//   xmldoc = xmlResponse.getElementsByTagName('IqomahSubuh');
//   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('iqmhs').value=myObj.IqomahSubuh;

//   xmldoc = xmlResponse.getElementsByTagName('IqomahDzuhur');
//   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('iqmhd').value=myObj.IqomahDzuhur;

//   xmldoc = xmlResponse.getElementsByTagName('IqomahAshar');
//   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('iqmha').value=myObj.IqomahAshar;

//   xmldoc = xmlResponse.getElementsByTagName('IqomahMaghrib');
//   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('iqmhm').value=myObj.IqomahMaghrib;

//   xmldoc = xmlResponse.getElementsByTagName('IqomahIsya');
//   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('iqmhi').value=myObj.IqomahIsya;

//   xmldoc = xmlResponse.getElementsByTagName('DurasiAdzan');
//   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('durasiadzan').value=myObj.DurasiAdzan;

//   xmldoc = xmlResponse.getElementsByTagName('Ihtiyati');
//   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('ihti').value=myObj.Ihtiyati;

//   xmldoc = xmlResponse.getElementsByTagName('Latitude');
//   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('latitude').value=myObj.Latitude;

//   xmldoc = xmlResponse.getElementsByTagName('Longitude');
//   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('longitude').value=myObj.Longitude;

//   xmldoc = xmlResponse.getElementsByTagName('ZonaWaktu');
//   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('zonawaktu').value=myObj.ZonaWaktu;

//   xmldoc = xmlResponse.getElementsByTagName('Hilal');
//   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('hilal').value=myObj.Hilal;

   document.getElementById('koreksihjr').value=myObj.koreksihjr;
   document.getElementById('dispimsyak').checked=!!myObj.dispimsyak;
   document.getElementById('ringimsyak').checked=!!myObj.ringimsyak;
   document.getElementById('disppuasa').checked=!!myObj.disppuasa;
   document.getElementById('dispiden').checked=!!myObj.dispiden;
   document.getElementById('dispdhuha').checked=!!myObj.dispdhuha;

//   xmldoc = xmlResponse.getElementsByTagName('NamaMasjid');
//   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('namamasjid').value=myObj.NamaMasjid;
   document.getElementById('informasi').value=myObj.informasi;
   document.getElementById('wsim').innerHTML=myObj.wsim;
   document.getElementById('wssh').innerHTML=myObj.wssh;
   document.getElementById('wstr').innerHTML=myObj.wstr;
   document.getElementById('wsdh').innerHTML=myObj.wsdh;
   document.getElementById('wsdz').innerHTML=myObj.wsdz;
   document.getElementById('wsas').innerHTML=myObj.wsas;
   document.getElementById('wsma').innerHTML=myObj.wsma;
   document.getElementById('wsis').innerHTML=myObj.wsis;
//   console.log(myObj.wsim);

//   console.log(myObj.koreksihjr);
 }
 
}

function handleJson(){
    if(xmlHttp.readyState==4 && xmlHttp.status==200){
    var myObj = JSON.parse(xmlHttp.responseText);
    console.log(myObj)
    document.getElementById('cblampu').checked = !myObj.cmdlampu;
    document.getElementById('cbintrpt').checked = myObj.interrupt;
//   xmlResponse=xmlHttp.responseXML;
//   console.log(xmlResponse);
//   xmldoc = xmlResponse.getElementsByTagName('rIqmhs');
//   message = xmldoc[0].firstChild.nodeValue;
//   document.getElementById('iqmhs').value=message;

 }
}

function selaraskan(){
    var now = new Date();
    let tgl = now.getDate();
    let bulan = now.getMonth();
    let tahun = now.getFullYear();
    let hari = now.getDay();
    let jam = now.getHours();
    let menit = now.getMinutes();
    let detik = now.getSeconds();
    let dataJson = {jam:jam, menit:menit, detik:detik, hari:hari, tgl:tgl, bulan:bulan+1, tahun:tahun}


    var xhr = new XMLHttpRequest();
    var url = "/selaraskan";

    xhr.onreadystatechange = function() {
        if(this.onreadyState == 4  && this.status == 200) {
        console.log(xhr.responseText);
        console.log("hahah");
        }
    };
    xhr.open("POST", url, true);
    xhr.send(JSON.stringify(dataJson));
    xhr.onloadend = function(){
        console.log(xhr.status);
        if(this.status == 200) {
        var myObj = JSON.parse(this.responseText);
        console.log(myObj);
        }else{
        selaraskan();
        }

    }

    console.log(dataJson)
}


function setJws() {
  
  console.log("tombol telah ditekan!");
  var iqmhs = document.getElementById("iqmhs").value;
  var iqmhd = document.getElementById("iqmhd").value;
  var iqmha = document.getElementById("iqmha").value;
  var iqmhm = document.getElementById("iqmhm").value;
  var iqmhi = document.getElementById("iqmhi").value;
  var durasiadzan = document.getElementById("durasiadzan").value;
  var ihti = document.getElementById("ihti").value;
  var latitude = document.getElementById("latitude").value;
  var longitude = document.getElementById("longitude").value;
  var zonawaktu = document.getElementById("zonawaktu").value;
  var hilal = document.getElementById("hilal").value;
  let koreksihjr = document.getElementById("koreksihjr").value;
  let dispimsyak = document.getElementById("dispimsyak").checked;
  let ringimsyak = document.getElementById("ringimsyak").checked;
  let disppuasa = document.getElementById("disppuasa").checked;
  let dispiden = document.getElementById("dispiden").checked;
  let dispdhuha = document.getElementById("dispdhuha").checked;
  var namamasjid = document.getElementById("namamasjid").value;
  let informasi = document.getElementById("informasi").value;
  
  var datajws = {iqmhs:iqmhs, iqmhd:iqmhd, iqmha:iqmha, iqmhm:iqmhm, iqmhi:iqmhi, durasiadzan:durasiadzan, ihti:ihti, latitude:latitude, longitude:longitude, zonawaktu:zonawaktu, hilal:hilal, koreksihjr:koreksihjr, dispimsyak:dispimsyak, ringimsyak:ringimsyak, disppuasa:disppuasa, dispiden:dispiden, dispdhuha:dispdhuha, namamasjid:namamasjid, informasi:informasi};
  
  var xhr = new XMLHttpRequest();
  var url = "/simpandatajws";
  
  xhr.onreadystatechange = function() {
    if(this.onreadyState == 4  && this.status == 200) {
      console.log(xhr.responseText);
    }
  };
  xhr.open("POST", url, true);
  xhr.send(JSON.stringify(datajws));
  
};


</script>

</html>


)=====";
