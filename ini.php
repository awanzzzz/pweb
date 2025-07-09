<?php
session_start();

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $nama = $_POST['nama'] ?? '';
    $email = $_POST['email'] ?? '';
    $password = $_POST['password'] ?? '';
    $confirm_password = $_POST['confirm-password'] ?? '';

    $penggunaBaru = [
        'nama' => $nama,
        'email' => $email,
        'password' => password_hash($password, PASSWORD_DEFAULT),
    ];

    if (!isset($_SESSION['pengguna'])) {
        $_SESSION['pengguna'] = [];
    }

    $_SESSION['pengguna'][] = $penggunaBaru;

    header('Location: header.php');
    exit;
}
