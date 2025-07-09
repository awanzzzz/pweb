<?php session_start(); ?>
<!DOCTYPE html>
<html lang="id">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Daftar Registrasi</title>
  <link rel="stylesheet" href="header.css">
</head>
<body>

<div class="navbar">
  <div class="logo">Sistem Registrasi</div>

  <?php if (isset($_SESSION['pengguna'])): ?>
    <div class="user-info">
      <h3>Daftar Semua Pengguna yang Pernah Registrasi:</h3>
      <hr>
      <?php foreach ($_SESSION['pengguna'] as $i => $user): ?>
        <div class="data-item">
          <strong>Pengguna <?= $i + 1 ?></strong><br>
          Nama: <?= htmlspecialchars($user['nama']) ?><br>
          Email: <?= htmlspecialchars($user['email']) ?><br>
          Password (hash): <?= htmlspecialchars($user['password']) ?>
        </div>
        <hr>
      <?php endforeach; ?>
    </div>
    <form action="reset.php" method="post" style="margin-top: 10px;">
    <button type="submit" class="logout-btn" style="background-color: #e74c3c;">Reset Semua Data</button>
    <a href="index.html" class="logout-btn">Kembali ke Registrasi</a>

</form>
  <?php else: ?>
    <p>Tidak ada data pengguna.</p>
    <a href="index.html">Registrasi Sekarang</a>
  <?php endif; ?>
</div>



</body>
</html>
