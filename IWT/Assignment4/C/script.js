"use strict";

      function replacer(key, value) {
        if (typeof value === "number" && !isFinite(value)) {
          return String(value);
        }
        return value;
      }

      function formatDate() {
        var dateString,
          date,
          curr_date,
          curr_month,
          curr_year,
          curr_day,
          json_day;
        dateString = document.getElementById("date");
        dateString = dateString.value.replace(/-/g, "/");
        date = new Date(dateString);

        curr_date = date.getDate();
        curr_month = date.getMonth() + 1; // Months are 0 based
        curr_year = date.getFullYear();
        curr_day = date.getDay();
        json_day = JSON.stringify(date.toJSON(), replacer);

        document.getElementById("dateObject").innerHTML =
          "<p> Default:<br/>" +
          date.toString() +
          "<\/p>" +
          "<p> Month-Day-Year:<br/>" +
          curr_month +
          "-" +
          curr_day +
          "-" +
          curr_year +
          "</p>" +
          "<p> Year-Month-Day:<br/> " +
          curr_year +
          "-" +
          curr_month +
          "-" +
          curr_day +
          "</p>" +
          "<p> JSON:<br/> " +
          json_day +
          "<\/p>";
      }

      function start() {
        var executeButton = document.getElementById("execute");
        executeButton.addEventListener("click", formatDate, false);
      }

      window.addEventListener("load", start, false);