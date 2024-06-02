import './App.css';

function App() {
  return (
    <div className="App">
      <header className="header">
        <ul className="menu">
          <a href="http://localhost:3001"><img className="logo" src="imagenes/logo.png" alt="logo"/></a>
          <li className="menu-item"><a href="#home">Home</a></li>
          <li className="menu-item"><a href="#about">Sobre Nosotros</a></li>
          <li className="menu-item"><a href="#contact">Contact</a></li>
        </ul>
      </header>
      <section className="background-section">
      </section>
      <footer className="footer">
        <p>© 2024 - Todos los derechos reservados</p>
        <ul className="menu-footer">
          <li><a href="#contacto">Contacto</a></li>
        </ul>
      </footer>
    </div>
  );
}

export default App;
