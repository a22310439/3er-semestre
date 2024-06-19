import React from 'react';
import { Link, useNavigate } from 'react-router-dom';
import { useAuth } from './authContext';

const Header = ({ title }) => {
  const { user, signOut } = useAuth();
  const navigate = useNavigate();

  const handleSignOut = () => {
    signOut();
    navigate('/');
  };

  return (
    <header className="header">
      <Link to="/" className="header-logo">
        <img className="logo" src="imagenes/logo.png" alt="logo" width='50px'/>
      </Link>
      <div className="menu-container">
        <ul className="menu">
          <li className="menu-item"><Link to="/">Inicio</Link></li>
          <li className="menu-item"><Link to="/sobrenosotros">Sobre Nosotros</Link></li>
          <li className="menu-item"><Link to="/contacto">Contacto</Link></li>
          <li className="menu-item"><Link to="/productos">Productos</Link></li>
          <li className="menu-item"><Link to="/servicios">Servicios</Link></li>
        </ul>
      </div>
      <div className="auth-container">
        {user ? (
          <button onClick={handleSignOut} className="signout-button">Cerrar Sesión</button>
        ) : (
          <Link to="/signin">Iniciar Sesión</Link>
        )}
      </div>
    </header>
  );
};

export default Header;
