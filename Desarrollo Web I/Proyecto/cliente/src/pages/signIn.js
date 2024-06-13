import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { useAuth } from '../components/authContext';
import { useUser } from '../components/userContext';

const SignIn = () => {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  const { signIn } = useAuth();
  const { users } = useUser();
  const navigate = useNavigate();

  const handleSignIn = () => {
    const user = users.find(u => u.username === username && u.password === password);
    if (user) {
      signIn(user.username, user.role);
      navigate(user.role === 'admin' ? '/pagAdmin' : '/pagUser');
    } else {
      alert('Credenciales incorrectas');
    }
  };

  return (
    <div className="form-container">
      <h2>Iniciar Sesión</h2>
      <div className="form-group">
        <label>Nombre de usuario:</label>
        <input
          type="text"
          value={username}
          onChange={(e) => setUsername(e.target.value)}
        />
      </div>
      <div className="form-group">
        <label>Contraseña:</label>
        <input
          type="password"
          value={password}
          onChange={(e) => setPassword(e.target.value)}
        />
      </div>
      <button className="submit-button" onClick={handleSignIn}>Iniciar Sesión</button>
    </div>
  );
};

export default SignIn;
