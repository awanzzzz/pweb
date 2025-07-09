<?php
session_start();
unset($_SESSION['pengguna']); 
header('Location: header.php');
exit;
