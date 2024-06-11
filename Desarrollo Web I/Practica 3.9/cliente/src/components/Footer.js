import React from 'react';

const Footer = () => {
  return (
    <footer className="footer">
      <div className="footer-content">
        <img src="/imagenes/logo.png" alt="Logo" className="footer-logo"/>
        <div className="footer-text">
          <ul className="footer-menu">
            <li className="footer-menu-item"><a href="/about">Sobre nosotros</a></li>
            <li className="footer-menu-item"><a href="/contact">Contacto</a></li>
          </ul>
          <p>Instituto Punto Alejandría © 2024</p>
        </div>
      </div>
    </footer>
  );
};

export default Footer;
