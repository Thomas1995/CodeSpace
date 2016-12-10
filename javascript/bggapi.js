function getInfo() {
  document.write("abc");
  var xhr = new XMLHttpRequest();
  xhr.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      alert(xhr.statusText);
    }
  };
  xhr.open("GET", "http://www.boardgamegeek.com/xmlapi/boardgame/39856/", true);
  xhr.send();
}
