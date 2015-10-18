# 
# Copyright (C) 2006-2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=twisted
PKG_VERSION:=15.1.0
PKG_RELEASE:=1

PKG_SOURCE:=Twisted-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=http://pypi.python.org/packages/source/T/Twisted/
PKG_MD5SUM:=df65e3da0bee81140e7637156802a518

PKG_BUILD_DIR:=$(BUILD_DIR)/Twisted-$(PKG_VERSION)
PKG_BUILD_DEPENDS:=python

include $(INCLUDE_DIR)/package.mk
$(call include_mk, python-package.mk)

define Package/twisted/default
  SUBMENU:=Python
  SECTION:=lang
  CATEGORY:=Languages
  URL:=http://twistedmatrix.com/
  DEPENDS:=+python
endef

define Package/twisted/default/description
 Twisted is a networking engine written in Python, supporting numerous 
 protocols. It contains a web server, numerous chat clients, chat servers, 
 mail servers, and more.
endef

define Package/twisted
$(call Package/twisted/default)
  TITLE:=Python networking engine
  DEPENDS+= +zope.interface +python-service-identity
endef

define Build/Compile
	$(call Build/Compile/PyMod,., install --prefix=/opt --root=$(PKG_INSTALL_DIR))
	$(SED) 's,#!.*,#!/opt/bin/python,' $(PKG_INSTALL_DIR)/opt/bin/*
endef

define Package/twisted/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
		$(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
		$(1)$(PYTHON_PKG_DIR)
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) \
		$(PKG_INSTALL_DIR)/opt/bin/* \
		$(1)/opt/bin
endef

$(eval $(call BuildPackage,twisted))
