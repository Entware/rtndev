#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# The newer version requires too many dependencies

include $(TOPDIR)/rules.mk

PKG_NAME:=geeknote
PKG_VERSION:=20140327
PKG_RELEASE:=2

PKG_REV:=c8a74e486ed9f906227f99bf532ba0688c25d0fe
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/VitaliyRodnenko/geeknote
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/geeknote
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+python +python-sqlite3 +python-openssl
	TITLE:=command line client for Evernote
	URL:=http://www.geeknote.me
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/geeknote/description
 Geeknote is an opensource console client for Evernote. Use it for system administration needs, 
 creating notes, notebooks, sync your local directories with Evernote notebooks.
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/geeknote/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/deb/geeknote.py $(1)/opt/bin/geeknote
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/deb/gnsync.py $(1)/opt/bin/gnsync
	$(SED) 's,^#!/usr/bin/env python,#!/opt/bin/python,g' \
	    $(1)/opt/bin/{geeknote,gnsync}
	$(INSTALL_DIR) $(1)/opt/usr/lib/geeknone/lib
	$(CP) $(PKG_BUILD_DIR)/lib/* $(1)/opt/usr/lib/geeknone/lib
	$(CP) ./files/httplib_TLSv1.py $(1)/opt/usr/lib/geeknone
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/{argparser,config,editor,geeknote,gnsync,log,oauth,out,storage,tools}.py $(1)/opt/usr/lib/geeknone
endef

$(eval $(call BuildPackage,geeknote))
