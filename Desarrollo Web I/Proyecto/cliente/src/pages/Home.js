import React from 'react';
import '../App.css';

const Home = () => {
  return (
    <div className="content">
      <div className="imagen-fondo">
        <h1>Instituto Punto Alejandría</h1>
        <div className="text-container">
          <h2><strong>Impulsando líderes competentes</strong></h2>
          <h3>Formación es nuestra misión</h3>
        </div>
        <div className='text-contactanos'>
          <h3>¡Contáctanos!</h3>
          <p>Teléfono: (33)3191-4694</p>
          <p>Correo: contacto@institutopuntoalejandria.com</p>
        </div>
      </div>
    </div>
  );
}

export default Home;
