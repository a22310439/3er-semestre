<?php
$total = 0;
for ($i = 1; $i <= 5; $i++) {
    $quantity = $_POST['cantidad'.$i];
    $price = $i * 100;
    $cost = $quantity * $price;
    $total += $cost;
    echo "Articulo $i: $quantity x $price = $cost<br>";
}
echo "Total: sdfas";
?>