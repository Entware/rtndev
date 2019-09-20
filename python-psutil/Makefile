#
# Copyright (C) 2008-2015 OpenWrt
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-psutil
PKG_VERSION:=5.6.3
PKG_RELEASE:=1

PKG_SOURCE:=psutil-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://files.pythonhosted.org/packages/1c/ca/5b8c1fe032a458c2c4bcbe509d1401dca9dda35c7fc46b36bb81c2834740
PKG_HASH:=863a85c1c0a5103a12c05a35e59d336e1d665747e531256e061213e2e90f63f3

PKG_BUILD_DEPENDS:=python

PKG_UNPACK=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xf $(DL_DIR)/$(PKG_SOURCE)

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/python-psutil
  SUBMENU:=Python
  SECTION:=lang
  CATEGORY:=Languages
  TITLE:=python-psutil
  URL:=https://github.com/giampaolo/psutil
  DEPENDS:=+python
endef

define Package/python-psutil/description
  psutil is a cross-platform library for retrieving information onrunning processes and system utilization (CPU, memory, disks, network) in Python
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

define Package/python-psutil/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
	    $(1)$(PYTHON_PKG_DIR)
	# fix python exec path in scripts
	find $(PKG_BUILD_DIR) -name *.py | xargs $(SED) 's|/usr/bin/env python|/opt/bin/python|'
endef

$(eval $(call BuildPackage,python-psutil))
