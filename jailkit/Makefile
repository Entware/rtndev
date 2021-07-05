#
# Copyright (C) 2020-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=jailkit
PKG_VERSION:=2.22
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://olivier.sessink.nl/jailkit
PKG_HASH:=985564721366eaf5c6482dd17e91647d21e70b4c9803c74847d649d8c8c2bbcf

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/jailkit
	SECTION:=admin
	CATEGORY:=Administration
	DEPENDS:=+python3 +libcap
	TITLE:=jailkit
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/jailkit/description
 Jailkit is a set of utilities to limit user accounts to specific files using
 chroot() and or specific commands. Setting up a chroot shell, a shell limited
 to some specific command, or a daemon inside a chroot jail is a lot easier and
 can be automated using these utilities.
endef

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/opt/include

define Package/jailkit/conffiles
/opt/etc/jailkit
endef

define Package/jailkit/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/jk_uchroot $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/jailkit
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/etc/jailkit/jk_*.ini \
		$(1)/opt/etc/jailkit
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/jk_* $(1)/opt/sbin
	$(SED) 's,^#!.*python,#!/opt/bin/python,' \
		$(1)/opt/sbin/jk_{check,cp,init,jailuser,list,update}
	$(INSTALL_DIR) $(1)/opt/share/jailkit
	$(CP) $(PKG_INSTALL_DIR)/opt/share/jailkit/jk_lib.py $(1)/opt/share/jailkit
endef

$(eval $(call BuildPackage,jailkit))
