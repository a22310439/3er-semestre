import React from 'react';
import '../App.css';

const Contact = () => {
  return (
    <div className="content">
      <h1>Contacto</h1>
      <p>Estamos ubicados entre la secretaría de tránsito y el estadio Jalisco en la ciudad de Guadalajara, Jalisco, México.</p>
      <p><strong>Dirección:</strong> Calle Aurelio González #2285, Jardines Alcalde, 44298</p>
      <p><strong>Teléfono:</strong> (333) 191-4694</p>
      <p><strong>Email:</strong> contacto@institutopuntoalejandria.com</p>
      <p>Estamos disponibles de lunes a viernes de 9:00 AM a 6:00 PM. No dudes en contactarnos para cualquier consulta o para más información sobre nuestros programas y certificaciones.</p>
      <div className="map-container">
        <iframe 
          src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d14928.184262783387!2d-103.32640405335749!3d20.708353915389946!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x8428b1cbedfdfd81%3A0xa6c34a3c432980b2!2sAurelio%20Gonz%C3%A1lez%202285%2C%20Jardines%20Alcalde%2C%2044298%20Guadalajara%2C%20Jal.!5e0!3m2!1sen!2smx!4v1717982691553!5m2!1sen!2smx"
          width="100%"
          height="450"
          style={{ border: 0 }}
          allowFullScreen=""
          loading="lazy"
          referrerPolicy="no-referrer-when-downgrade"
          title="Google Maps Location"
        ></iframe>
      </div>
    </div>
  );
};

export default Contact;
