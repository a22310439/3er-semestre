import React from 'react';
import './App.css';
import Home from './pages/Home';
import About from './pages/About';
import Contact from './pages/Contact';
import SignIn from './pages/signIn';
import PagAdmin from './pages/pagAdmin';
import PagUser from './pages/pagUser';
import Header from './components/Header';
import Footer from './components/Footer';
import Productos from './pages/Productos';
import Servicios from './pages/Servicios';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import { AuthProvider } from './components/authContext';
import { UserProvider } from './components/userContext';

const App = () => {
  return (
    <AuthProvider>
      <UserProvider>
        <Router>
          <div className="app-container">
            <Header title="Proyecto" />
            <Routes>
              <Route path="/" element={<Home />} />
              <Route path="/sobrenosotros" element={<About />} />
              <Route path="/contacto" element={<Contact />} />
              <Route path="/signin" element={<SignIn />} />
              <Route path="/pagAdmin" element={<PagAdmin />} />
              <Route path="/pagUser" element={<PagUser />} />
              <Route path="/productos" element={<Productos />} />
              <Route path="/servicios" element={<Servicios />} />
            </Routes>
            <Footer />
          </div>
        </Router>
      </UserProvider>
    </AuthProvider>
  );
};

export default App;
