#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=sshguard
PKG_VERSION:=2.4.2
PKG_REV:=77589e10f3ed70d14c2adb931a7482a96d9a4bbf
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://bitbucket.org/sshguard/sshguard.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=1b9d6bbc0ad302ffea6023075f45bdde8306ed164bf006659ff5afd4a73ac044

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/sshguard
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Firewall
	TITLE:=bruteforce protection
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/sshguard/description
 SSHGuard protects hosts from brute-force attacks against SSH and other
 services. It aggregates system logs and blocks repeat offenders using
 one of several firewall backends.
endef

define Package/sshguard/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/sshguard $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/sshg-* $(1)/opt/lib
endef

$(eval $(call BuildPackage,sshguard))
