#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=sshguard
PKG_VERSION:=2.4.3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/sshguard
PKG_HASH:=64029deff6de90fdeefb1f497d414f0e4045076693a91da1a70eb7595e97efeb

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/sshguard
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Firewall
	TITLE:=bruteforce protection
	URL:=https://www.sshguard.net
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
