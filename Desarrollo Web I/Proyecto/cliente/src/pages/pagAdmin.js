import React, { useState } from 'react';
import { useUser } from '../components/userContext';

const PagAdmin = () => {
  const { users, setUsers } = useUser();
  const [newUser, setNewUser] = useState({ username: '', password: '', role: 'user' });
  const [editUser, setEditUser] = useState(null);

  const addUser = () => {
    if (!newUser.username || !newUser.password) return; // Validación básica
    setUsers([...users, newUser]);
    setNewUser({ username: '', password: '', role: 'user' });
  };

  const deleteUser = (username) => {
    setUsers(users.filter(user => user.username !== username));
  };

  const startEditUser = (user) => {
    setEditUser(user);
  };

  const saveEditUser = () => {
    setUsers(users.map(user => (user.username === editUser.username ? editUser : user)));
    setEditUser(null);
  };

  return (
    <div className="admin-container">
      <h1>Administrar Usuarios</h1>
      <div>
        <h2>Usuarios Existentes</h2>
        <div className="user-list-header">
          <div>Usuario</div>
          <div>Contraseña</div>
          <div>Rol</div>
          <div>Acciones</div>
        </div>
        <ul className="user-list">
          {users.map(user => (
            <li key={user.username}>
              {editUser && editUser.username === user.username ? (
                <div className="user-details">
                  <div>
                    <input
                      type="text"
                      value={editUser.username}
                      onChange={(e) => setEditUser({ ...editUser, username: e.target.value })}
                    />
                  </div>
                  <div>
                    <input
                      type="password"
                      value={editUser.password}
                      onChange={(e) => setEditUser({ ...editUser, password: e.target.value })}
                    />
                  </div>
                  <div>
                    <select
                      value={editUser.role}
                      onChange={(e) => setEditUser({ ...editUser, role: e.target.value })}
                    >
                      <option value="user">User</option>
                      <option value="admin">Admin</option>
                    </select>
                  </div>
                  <div className="user-actions">
                    <button onClick={saveEditUser} className="edit-button">Guardar</button>
                    <button onClick={() => setEditUser(null)} className='cancel-button'>Cancelar</button>
                  </div>
                </div>
              ) : (
                <div className="user-details">
                  <div>{user.username}</div>
                  <div>{user.password}</div>
                  <div>{user.role}</div>
                  <div className="user-actions">
                    <button onClick={() => startEditUser(user)} className="edit-button">Editar</button>
                    <button onClick={() => deleteUser(user.username)} className="delete-button">Eliminar</button>
                  </div>
                </div>
              )}
            </li>
          ))}
        </ul>
      </div>
      <div className="add-user-container">
        <h2>Agregar Usuario</h2>
        <input
          type="text"
          placeholder="Nombre de usuario"
          value={newUser.username}
          onChange={(e) => setNewUser({ ...newUser, username: e.target.value })}
        />
        <input
          type="text"
          placeholder="Contraseña"
          value={newUser.password}
          onChange={(e) => setNewUser({ ...newUser, password: e.target.value })}
        />
        <select
          value={newUser.role}
          onChange={(e) => setNewUser({ ...newUser, role: e.target.value })}
        >
          <option value="user">User</option>
          <option value="admin">Admin</option>
        </select>
        <button onClick={addUser}>Agregar</button>
      </div>
    </div>
  );
};

export default PagAdmin;
