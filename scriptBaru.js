document.getElementById('registrationForm').addEventListener('submit', function(e) {
    e.preventDefault();
    
    const name = document.getElementById('name').value.trim();
    const email = document.getElementById('email').value.trim();
    const password = document.getElementById('password').value;
    const konfirmasi = document.getElementById('confirm-password').value;
    
    let apakahValid = true;

    if (name === '') {
        showError('name-error', 'Nama harus diisi');
        apakahValid = false;
    } else {
        hideError('name-error');
    }

    if (!emailValid(email)) {
        showError('email-error', 'Email tidak valid');
        apakahValid = false;
    } else {
        hideError('email-error');
    }

    if (password.length < 6) {
        showError('password-error', 'Password minimal 6 karakter');
        apakahValid = false;
    } else {
        hideError('password-error');
    }

    if (password !== konfirmasi) {
        showError('confirm-error', 'Password tidak cocok');
        hideSuccess('password-match');
        apakahValid = false;
    } else if (konfirmasi.length > 0) {
        hideError('confirm-error');
        showSuccess('password-match', 'Password cocok!');
    }

    if (apakahValid) {
        this.submit();
    }
});

function emailValid(email) {
    const re = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return re.test(email);
}

function showError(id, message) {
    const element = document.getElementById(id);
    element.textContent = message;
    element.style.display = 'block';
}

function hideError(id) {
    document.getElementById(id).style.display = 'none';
}

function showSuccess(id, message) {
    const element = document.getElementById(id);
    element.textContent = message;
    element.style.display = 'block';
}

function hideSuccess(id) {
    document.getElementById(id).style.display = 'none';
}

document.getElementById('confirm-password').addEventListener('input', function() {
    const password = document.getElementById('password').value;
    const konfirmasi = this.value;

    if (konfirmasi.length > 0) {
        if (password !== konfirmasi) {
            showError('confirm-error', 'Password tidak cocok');
            hideSuccess('password-match');
        } else {
            hideError('confirm-error');
            showSuccess('password-match', 'Password cocok!');
        }
    } else {
        hideError('confirm-error');
        hideSuccess('password-match');
    }
});
