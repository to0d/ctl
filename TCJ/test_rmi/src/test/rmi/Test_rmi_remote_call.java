package test.rmi;

import java.net.MalformedURLException;
import java.rmi.AlreadyBoundException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.server.UnicastRemoteObject;

public class Test_rmi_remote_call {

	static interface IAction extends Remote {

		public String doAction(String arg) throws RemoteException;

		public void shutdown() throws RemoteException;
	}

	static class XAction extends UnicastRemoteObject implements IAction {

		private static final long serialVersionUID = 6530029834182302658L;

		public XAction() throws RemoteException {
		}

		public String doAction(String arg) throws RemoteException {
			return "doAction(" + arg + ")";
		}

		public void shutdown() throws RemoteException {
			System.out.println("server shutdown");
			System.exit(0);
		}
	}

	static final String REMOTE_ACTION_NAME = "MY_Action";

	static final int REMOTE_PORT = 8888;

	public static void main(String args[]) {

		/***************************************/
		// Server part
		/***************************************/
		try {

			// register remote action
			LocateRegistry.createRegistry(REMOTE_PORT);
			Naming.bind(String.format("rmi://localhost:%d/%s", REMOTE_PORT, REMOTE_ACTION_NAME), new XAction());
			System.out.println("Remote: action register done");

		} catch (RemoteException | AlreadyBoundException | MalformedURLException e) {
			e.printStackTrace();
		}

		/***************************************/
		// Client part
		/***************************************/
		try {
			// Get remote action
			IAction action = (IAction) Naming
					.lookup(String.format("rmi://localhost:%d/%s", REMOTE_PORT, REMOTE_ACTION_NAME));

			System.out.println(action.doAction("abc"));
			action.shutdown();

		} catch (NotBoundException | RemoteException | MalformedURLException e) {
			e.printStackTrace();
		}
	}
}