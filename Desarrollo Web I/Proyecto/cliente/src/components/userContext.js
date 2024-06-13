import React, { createContext, useState, useContext } from 'react';

const UserContext = createContext();

export const useUser = () => useContext(UserContext);

export const UserProvider = ({ children }) => {
  const [users, setUsers] = useState([
    { username: 'admin', password: 'admin', role: 'admin' },
    { username: 'user', password: 'user', role: 'user' },
    { username: 'test', password: 'test', role: 'user' },
    { username: 'test2', password: 'test2', role: 'user' },
    { username: 'test3', password: 'test3', role: 'user' },
  ]);

  return (
    <UserContext.Provider value={{ users, setUsers }}>
      {children}
    </UserContext.Provider>
  );
};
