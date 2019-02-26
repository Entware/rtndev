#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-cups
PKG_VERSION:=1.9.74
PKG_RELEASE:=1

PKG_SOURCE:=pycups-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://files.pythonhosted.org/packages/00/ce/836a0deb8b24bcd5f850f8fb97f99fb4abd7374e078b9e6df5a0838f8eb5
PKG_HASH:=86090f259a7c5d0d5caa3407a0e57c9e134027620cbc8f90bf4e37c8b53ed7b9

PKG_BUILD_DIR:=$(BUILD_DIR)/pycups-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/python-cups
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python +cups
	TITLE:=Python bindings for the CUPS API
	URL:=http://cyberelk.net/tim/software/pycups/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/python-cups/description
 This is a Python bindings for the CUPS API, known as pycups. It was written
 for use with system-config-printer, but can be put to other uses as well.
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

define Package/python-cups/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
		$(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
		$(1)$(PYTHON_PKG_DIR)
endef

$(eval $(call BuildPackage,python-cups))
