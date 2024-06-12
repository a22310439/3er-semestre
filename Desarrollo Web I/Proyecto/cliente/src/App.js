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
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import { AuthProvider } from './components/authContext';
import ProtectedRoute from './components/protectedRoute';

const App = () => {
  return (
    <AuthProvider>
      <Router>
        <div className="app-container">
          <Header title="Proyecto" />
          <Routes>
            <Route path="/" element={<Home />} />
            <Route path="/about" element={<About />} />
            <Route path="/contact" element={<Contact />} />
            <Route path="/signin" element={<SignIn />} />
            <Route path="/pagAdmin" element={<ProtectedRoute role="admin"><PagAdmin /></ProtectedRoute>} />
            <Route path="/pagUser" element={<ProtectedRoute role="user"><PagUser /></ProtectedRoute>} />
          </Routes>
          <Footer />
        </div>
      </Router>
    </AuthProvider>
  );
};

export default App;
