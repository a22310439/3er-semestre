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
        <div className='contactanos-container'>
          <h2><strong>¡Contáctanos!</strong></h2>
          <p><strong>Teléfono: (33)3191 4694</strong></p>
          <p><strong>Correo: contacto@institutopunntoalejandria.com</strong></p>
        </div>
      </div>
    </div>
  );
}

export default Home;