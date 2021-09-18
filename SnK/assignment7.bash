#!/bin/bash
echo -n "Enter dividend: "
read dividend
echo -n "Enter divisor: "
read divisor
quotient=$((dividend/divisor))
remainder=$((dividend%divisor))
echo "Quotient: $quotient"
echo "Remainder: $remainder"