import React, { useState } from 'react';
import '../App.css';
import { useNavigate } from 'react-router-dom';
import { useAuth } from '../components/authContext';

const data = [
    { username: 'admin', password: 'admin', role: 'admin'},
    { username: 'user', password: 'user', role: 'user'},
    { username: 'test', password: 'test', role: 'user'},
    { username: 'test2', password: 'test2', role: 'user'},
    { username: 'test3', password: 'test3', role: 'user'}
];

const SignIn = () => {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  const { signIn } = useAuth();
  const navigate = useNavigate();

  const handleSubmit = (e) => {
    e.preventDefault();
    const user = data.find(user => user.username === username && user.password === password);
    if (user) {
      signIn(user.username, user.role);
      if (user.role === 'admin') {
        navigate('/pagAdmin');
      } else {
        navigate('/pagUser');
      }
    } else {
      console.log('Usuario o contraseña incorrectos');
    }
  };

  return (
    <div className="content">
      <h1>Iniciar Sesión</h1>
      <form onSubmit={handleSubmit} className="form-container">
        <div className="form-group">
          <label htmlFor="username">Nombre de Usuario:</label>
          <input
            type="text"
            id="username"
            value={username}
            onChange={(e) => setUsername(e.target.value)}
            required
          />
        </div>
        <div className="form-group">
          <label htmlFor="password">Contraseña:</label>
          <input
            type="password"
            id="password"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
            required
          />
        </div>
        <button type="submit" className="submit-button">Iniciar Sesión</button>
      </form>
    </div>
  );
};

export default SignIn;
