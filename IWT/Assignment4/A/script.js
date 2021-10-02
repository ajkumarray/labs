var total = [, , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
var face1;
var face2;

//  function to calculate sum
for (var x = 1; x <= 36000; x++) {
    face1 = rollDie();
    face2 = rollDie();
    ++total[face1 + face2];
}

outputResults();


//  function to roll dice
function rollDie() {
    return Math.floor(1 + Math.random() * 6);
}

//  function to print table
function outputResults() {
    document.write('<table border = "1">');
    document.write("<tr><th width = '100'>Sum of Dice" +'<th width = "200">Total Times Rolled</tr>');

    for (var i = 2; i < total.length; i++)
      document.write("<tr><td>" + i + "<td>" + total[i] + "</tr>");

    document.write("</table>");
}