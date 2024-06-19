import React from 'react';
import { Link } from 'react-router-dom';

const Footer = () => {
  return (
    <footer className="footer">
      <div className="footer-content">
        <img src="/imagenes/logo.png" alt="Logo" className="footer-logo"/>
        <div className="footer-text">
          <ul className="footer-menu">
            <li className="footer-menu-item"><Link to="/about">Sobre Nosotros</Link></li>
            <li className="footer-menu-item"><Link to="/contact">Contacto</Link></li>
          </ul>
          <p>Instituto Punto Alejandría © 2024</p>
        </div>
      </div>
    </footer>
  );
};

export default Footer;
