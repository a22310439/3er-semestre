// Header.js
import React from 'react';
import { Link } from 'react-router-dom';

const Header = ({ title }) => {
  return (
    <header className="header">
      <Link to="/" className="header-logo">
        <img className="logo" src='imagenes/logo.png' alt="logo" width="70px" />
      </Link>
      <ul className="menu">
        <li className="menu-item"><Link to="/">Inicio</Link></li>
        <li className="menu-item"><Link to="/about">Sobre Nosotros</Link></li>
        <li className="menu-item"><Link to="/contact">Contacto</Link></li>
      </ul>
    </header>
  );
}

export default Header;
