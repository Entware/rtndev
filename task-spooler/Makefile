#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# The newer versions requires CUDA libraries

include $(TOPDIR)/rules.mk

PKG_NAME:=task-spooler
PKG_VERSION:=1.3.0
PKG_REV:=052db94bc588e4f4471e37599dfdff77dc44c8bb
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/justanhduc/task-spooler.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=b4493ab5c359714b78a567d475c7fb014bb0fcb230597181c93f693ba5f6f917

include $(INCLUDE_DIR)/package.mk

define Package/task-spooler
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=task spooler
	URL:=http://tcforge.berlios.de/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/task-spooler/description
 Task spooler is a Unix batch system where the tasks spooled run one after
 the other. The amount of jobs to run at once can be set at any time. Each user
 in each system has his own job queue. The tasks are run in the correct context
 (that of enqueue) from any shell/process, and itask-spooler output/resultask-spooler can be easily
 watched.
endef

define Package/task-spooler/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ts $(1)/opt/bin/tsp
endef

$(eval $(call BuildPackage,task-spooler))
