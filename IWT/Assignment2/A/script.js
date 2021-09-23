function calculator() {
    var itemcount, i, cal, sum = 0;
    itemcount = prompt("How many items Salesman sold last week:");
    var count = parseInt(itemcount);
    for (i = 0; i < count; i++) {
      cal = prompt("Enter item number:");
      var getprice = parseInt(cal);
      if (getprice == 1) {
        sum = sum + 239.99;
      } else if (getprice == 2) {
        sum = sum + 129.75;
      } else if (getprice == 3) {
        sum = sum + 99.95;
      } else if (getprice == 4) {
        sum = sum + 350.89;
      }
    }
    var sal = 200 + (9 / 100) * parseInt(sum);
    document.write(
      "<h1> Total Salary for this salesperson is: " + sal + "</h1>"
    );
  }