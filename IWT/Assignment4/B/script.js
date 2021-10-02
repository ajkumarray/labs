function search1() {
    var str1 = document.getElementById("string1").value;
    var str2 = document.getElementById("string2").value;
    var len = str1.length;
    var count = 0;
    var search = str1.indexOf(str2);
    for (i = 0; i < len; i++) {
      if (parseInt(search) != -1) {
        count++;
        var search = str1.indexOf(str2, parseInt(search) + 1);
      }
    }
    document.getElementById("ans").value =
      str2 + " Occurs " + count + " times";
  }