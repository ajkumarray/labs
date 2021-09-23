function EncryptNumber() {
    var digit1, digit2, digit3, digit4, inputString;

    inputString = prompt("Please enter a 4 digit number");

    var number = parseInt(inputString);

    digit1 = parseInt((number / 1000 + 7) % 10);
    digit2 = parseInt(((number % 1000) / 100 + 7) % 10);
    digit3 = parseInt((((number % 1000) % 100) / 10 + 7) % 10);
    digit4 = parseInt((((number % 1000) % 100) / 10 + 7) % 10);

    var encryptedNum;
    encryptedNum =
      "The encrypted number is " + digit1 + digit2 + digit3 + digit4;

    document.write("<br>" + encryptedNum);
  }