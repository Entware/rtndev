#
# Copyright (C) 2008-2015 OpenWrt
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-psutil
PKG_VERSION:=5.4.8
PKG_RELEASE:=1

PKG_SOURCE:=psutil-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://files.pythonhosted.org/packages/e3/58/0eae6e4466e5abf779d7e2b71fac7fba5f59e00ea36ddb3ed690419ccb0f
PKG_HASH:=6e265c8f3da00b015d24b842bfeb111f856b13d24f2c57036582568dc650d6c3

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
